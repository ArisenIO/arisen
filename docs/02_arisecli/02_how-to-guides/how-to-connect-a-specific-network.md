## Goal

Connect to a specific `aos` or `awalletd` host to send COMMAND

`arisecli` and `awalletd` can connect to a specific node by using the `--url` or `--wallet-url` optional arguments, respectively, followed by the http address and port number these services are listening to.

[[info | Default address:port]]
| If no optional arguments are used (i.e. `--url` or `--wallet-url`), `arisecli` attempts to connect to a local `aos` or `awalletd` running at localhost `127.0.0.1` and default port `12518`.

## Before you begin

* Install the currently supported version of `arisecli`

## Steps
### Connecting to Aos

```sh
arisecli -url http://aos-host:12518 COMMAND
```

### Connecting to Awalletd

```sh
arisecli --wallet-url http://awalletd-host:12518 COMMAND
```
