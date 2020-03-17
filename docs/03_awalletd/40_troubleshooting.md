---
content_title: Awalletd Troubleshooting
---

## How to solve the error "Failed to lock access to wallet directory; is another `awalletd` running"?

Since `arisecli` may auto-launch an instance of `awalletd`, it is possible to end up with multiple instances of `awalletd` running. That can cause unexpected behavior or the error message above.

To fix this issue, you can terminate all running `awalletd` instances and restart `awalletd`. The following command will find and terminate all instances of `awalletd` running on the system:

```sh
pkill awalletd
```
