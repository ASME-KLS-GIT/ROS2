# Introduction to ROS2

---

[![My Skills|173](https://camo.githubusercontent.com/1c9b41da2517c816b3a056c53c5567288c8173292587f1ae130f14150ddadc25/68747470733a2f2f736b696c6c69636f6e732e6465762f69636f6e733f693d6370702c707974686f6e2c726f73)](https://skillicons.dev)

---

## TRACKS AND STRUCTURE OF THIS REPOSITORY

---

This repository will be carried forward in two tracks with respect to the languages being used in order to write the ROS2 entities.

The repository will be split into :

1. C++ Track.
2. Python Track.
3. Topics common to both the tracks.

## Links

---


### Resouces and Project Implementations

---

ROS2 Jazzy Official Documentation :<https://docs.ros.org/en/jazzy/index.html>

Basic URDF bot control with ROS2 : <https://github.com/fuzzytron-Vivek/Knight-in-Love>


---

## Docs site

This repo also powers a polished GitHub Pages documentation site, built
with MkDocs Material: concept guides, side-by-side Python/C++ examples,
and an API cheat sheet — all backed by code that's actually built and
run in CI rather than just pasted in.

**Live site:** `https://asme-kls-git.github.io/ROS2/` *(once Pages is enabled — see below)*

### What's new, and how it fits with the rest of this repo

```
docs/          # the site content (Markdown) - concepts, examples, cheat sheet
examples/      # real, buildable ROS2 packages - source of truth for code shown on the site
mkdocs.yml     # site configuration
.github/workflows/
  deploy.yml           # builds + deploys the docs site to GitHub Pages on push to master
  verify-examples.yml  # builds & runs the packages in examples/ inside a real ROS2 container
```

`ROS2_general/`, `cpp_ros/`, and `py_ros/` are untouched — they stay the
home for raw notes and experiments. `docs/` and `examples/` are a
separate, more curated layer: every code block shown on the website is
*included* directly from a file in `examples/`, via MkDocs' snippet
syntax, so the published guide can never quietly drift out of sync with
code that's actually been tested. `.github/workflows/verify-examples.yml`
enforces that by building and running those packages in an
`osrf/ros:jazzy-desktop` container on every change.

### Preview the docs site locally

```bash
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
mkdocs serve
```

Then open `http://127.0.0.1:8000`.

### One-time setup to go live

In this repo: **Settings → Pages** → set **Source** to **GitHub Actions**.
`deploy.yml` then builds and deploys the site automatically on every push
to `master` — no further steps needed after that.
