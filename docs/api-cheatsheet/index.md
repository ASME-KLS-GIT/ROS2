# API Cheat Sheet: rclpy vs rclcpp

A quick side-by-side reference for the calls you'll use in almost every
ROS2 node, in both client libraries. This isn't exhaustive — it's the 20%
of the API that shows up in 80% of basic nodes.

| Task                        | Python (`rclpy`)                                            | C++ (`rclcpp`)                                                        |
|------------------------------|--------------------------------------------------------------|-------------------------------------------------------------------------|
| Initialize the client library | `rclpy.init(args=args)`                                      | `rclcpp::init(argc, argv)`                                              |
| Define a node                 | `class MyNode(Node): def __init__(self): super().__init__('my_node')` | `class MyNode : public rclcpp::Node { public: MyNode() : Node("my_node") {} };` |
| Create a publisher             | `self.create_publisher(MsgType, 'topic', 10)`                | `this->create_publisher<MsgType>("topic", 10)`                          |
| Create a subscription          | `self.create_subscription(MsgType, 'topic', callback, 10)`   | `this->create_subscription<MsgType>("topic", 10, callback)`             |
| Create a timer                 | `self.create_timer(period_sec, callback)`                    | `this->create_wall_timer(500ms, callback)`                              |
| Log a message                  | `self.get_logger().info('text')`                              | `RCLCPP_INFO(this->get_logger(), "text")`                               |
| Hand control to the executor   | `rclpy.spin(node)`                                            | `rclcpp::spin(node_ptr)`                                                 |
| Clean shutdown                 | `node.destroy_node()` then `rclpy.shutdown()`                 | `rclcpp::shutdown()`                                                     |

!!! warning "Don't copy signatures from memory"
    These signatures are accurate for current ROS2 distros (Humble
    through Lyrical) as of this writing, but client library APIs do
    evolve. If something here doesn't match what you see in your
    editor's autocomplete or the official docs for your installed distro,
    trust your installed distro — and consider opening an issue on this
    repo so the page can be corrected.

See the [Publisher & Subscriber example](../examples/publisher-subscriber.md)
for these calls used in a complete, runnable node.
