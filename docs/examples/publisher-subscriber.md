# Example: Publisher & Subscriber

This builds exactly the graph from the [Nodes & Topics](../concepts/nodes-and-topics.md)
guide: a `talker` node that publishes a `std_msgs/String` on `/topic` every
half second, and a `listener` node that subscribes and logs what it
receives.

Pick your language below — the two versions are functionally identical.

## 1. Package layout

=== "Python (rclpy)"

    ROS2 Python packages use `ament_python`. The layout the code below
    assumes:

    ```text
    py_pubsub/
    ├── package.xml
    ├── setup.py
    ├── setup.cfg
    ├── resource/
    │   └── py_pubsub
    └── py_pubsub/
        ├── __init__.py
        ├── publisher_member_function.py
        └── subscriber_member_function.py
    ```

=== "C++ (rclcpp)"

    ROS2 C++ packages use `ament_cmake`. The layout the code below assumes:

    ```text
    cpp_pubsub/
    ├── package.xml
    ├── CMakeLists.txt
    └── src/
        ├── publisher_member_function.cpp
        └── subscriber_member_function.cpp
    ```

## 2. The publisher

=== "Python (rclpy)"

    ```python title="py_pubsub/publisher_member_function.py"
    --8<-- "py_pubsub/py_pubsub/publisher_member_function.py"
    ```

    Walking through the parts that matter:

    - `create_publisher(String, 'topic', 10)` — creates a publisher on
      the `/topic` topic, typed for `std_msgs/msg/String`, with a QoS
      history depth of 10.
    - `create_timer(0.5, self.timer_callback)` — calls `timer_callback`
      every 0.5 seconds; this is what drives the publish loop instead of
      a manual `while True`.
    - `rclpy.spin(minimal_publisher)` — hands control to ROS2's executor,
      which is what actually invokes your timer callback on schedule.

=== "C++ (rclcpp)"

    ```cpp title="cpp_pubsub/src/publisher_member_function.cpp"
    --8<-- "cpp_pubsub/src/publisher_member_function.cpp"
    ```

    Walking through the parts that matter:

    - `create_publisher<std_msgs::msg::String>("topic", 10)` — same role
      as the Python version: a typed publisher on `/topic` with a QoS
      history depth of 10.
    - `create_wall_timer(500ms, ...)` — the C++ equivalent of the Python
      timer, using `std::bind` to hook up the member function callback.
    - `rclcpp::spin(...)` — the C++ executor loop; nothing runs until
      this is called.

## 3. The subscriber

=== "Python (rclpy)"

    ```python title="py_pubsub/subscriber_member_function.py"
    --8<-- "py_pubsub/py_pubsub/subscriber_member_function.py"
    ```

    `create_subscription(String, 'topic', self.listener_callback, 10)`
    registers `listener_callback` to run every time a message arrives on
    `/topic`. The QoS depth (`10`) must be compatible with the
    publisher's — for this simple case, matching values is the safe
    default.

=== "C++ (rclcpp)"

    ```cpp title="cpp_pubsub/src/subscriber_member_function.cpp"
    --8<-- "cpp_pubsub/src/subscriber_member_function.cpp"
    ```

    Same shape as the Python version: `create_subscription<...>` binds
    `topic_callback` to incoming messages on `/topic`.

## 4. Build it

=== "Python (rclpy)"

    Python packages don't need compiling, but they still go through
    `colcon build` so ROS2 can register the entry points and resource
    index:

    ```bash
    cd ~/ros2_ws
    colcon build --packages-select py_pubsub
    source install/setup.bash
    ```

=== "C++ (rclcpp)"

    ```bash
    cd ~/ros2_ws
    colcon build --packages-select cpp_pubsub
    source install/setup.bash
    ```

## 5. Run it

Open two terminals, source your workspace in both, then:

```bash
# Terminal 1
ros2 run py_pubsub listener   # or: ros2 run cpp_pubsub listener

# Terminal 2
ros2 run py_pubsub talker     # or: ros2 run cpp_pubsub talker
```

You should see the talker logging `Publishing: 'Hello World: 0'` (or
`Hello, world! 0` in C++) and the listener logging a matching
`I heard: '...'` line every half second. Stop both with ++ctrl+c++.

!!! example "Try it"
    Mix and match — run the Python `talker` against the C++ `listener`,
    or vice versa. Because both speak the same `std_msgs/String` message
    type over the same `/topic` name, ROS2 doesn't care which language
    either side is written in. That's the payoff of the decoupling
    described in [Nodes & Topics](../concepts/nodes-and-topics.md).
