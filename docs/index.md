# Learn ROS2

A small, focused set of guides for people who want to actually understand
ROS2 — not just copy-paste a tutorial. Every code sample on this site is
pulled directly from a package that's built and run in CI on every change,
so what you read here is what actually works.

## Where to start

<div class="grid cards" markdown>

- **New to ROS2?** Start with [Concepts](concepts/index.md) to get the
  mental model (nodes, topics, the pub/sub pattern) before writing any code.
- **Want to see it run?** Jump to [Examples](examples/index.md) for a
  minimal, working publisher/subscriber in Python and C++.
- **Already know the shape, forgot the syntax?** The
  [API Cheat Sheet](api-cheatsheet/index.md) puts rclpy and rclcpp calls
  side by side.

</div>

## Which ROS2 distro does this target?

Examples on this site are built and tested against **Jazzy Jalisco**
(2024 LTS, supported through 2029). The core concepts here — nodes,
topics, publishers, subscribers — have been essentially unchanged since
early ROS2 releases, so everything on this site applies just as well if
you're on Humble Hawksbill (2022 LTS) or the newer Lyrical Luth (2026 LTS).
Anywhere a distro-specific difference matters, the page will call it out
explicitly.

## Prerequisites

- Basic comfort with the Linux command line.
- Python or C++ fundamentals (you don't need both — pick the language tab
  that matches you on each example page).
- A working ROS2 install. If you don't have one yet, follow the
  [official installation guide](https://docs.ros.org/) for your distro
  before starting the examples.

## More from this repo

This site covers polished, verified guides — but the
[ASME-KLS-GIT/ROS2](https://github.com/ASME-KLS-GIT/ROS2) repo it's built
from also has:

- Raw notes and experiments in
  [`ROS2_general`](https://github.com/ASME-KLS-GIT/ROS2/tree/master/ROS2_general),
  [`cpp_ros`](https://github.com/ASME-KLS-GIT/ROS2/tree/master/cpp_ros), and
  [`py_ros`](https://github.com/ASME-KLS-GIT/ROS2/tree/master/py_ros).
- Curated video playlists (AutomaticAddison's C++, Python, and ROS2
  fundamentals series) linked from the
  [repo README](https://github.com/ASME-KLS-GIT/ROS2#readme).

!!! tip "How this site is built"
    Curious about the tooling, or want to contribute a new guide? See the
    project [README](https://github.com/ASME-KLS-GIT/ROS2#readme) for how
    the docs, the tested example packages, and the CI pipeline fit
    together.
