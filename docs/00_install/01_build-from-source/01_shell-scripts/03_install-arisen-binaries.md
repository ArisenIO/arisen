---
content_title: Install ARISEN Binaries
---

## ARISEN install script

For ease of contract development, content can be installed at the `/usr/local` folder using the `arisen_install.sh` script within the `rsn/scripts` folder. Adequate permission is required to install on system folders:

```sh
cd ~/arisen/rsn
sudo ./scripts/arisen_install.sh
```

## ARISEN manual install

In lieu of the `arisen_install.sh` script, you can install the ARISEN binaries directly by invoking `make install` within the `rsn/build` folder. Again, adequate permission is required to install on system folders:

```sh
cd ~/arisen/rsn/build
sudo make install
```

[[info | What's Next?]]
| Configure and use [Aos](../../../01_aos/index.md), or optionally [Test the ARISEN binaries](04_test-arisen-binaries.md).
