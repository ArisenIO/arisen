---
content_title: Download ARISEN Source
---

To download the ARISEN source code, clone the `rsn` repo and its submodules. It is adviced to create a home `arisen` folder first and download all the ARISEN related software there:

```sh
mkdir -p ~/arisen && cd ~/arisen
git clone --recursive https://github.com/arisenio/arisen
```

## Update Submodules

If a repository is cloned without the `--recursive` flag, the submodules *must* be updated before starting the build process:

```sh
cd ~/arisen/rsn
git submodule update --init --recursive
```

## Pull Changes

When pulling changes, especially after switching branches, the submodules *must* also be updated. This can be achieved with the `git submodule` command as above, or using `git pull` directly:

```sh
[git checkout <branch>]  (optional)
git pull --recurse-submodules
```

[[info | What's Next?]]
| [Build ARISEN binaries](02_build-arisen-binaries.md)
