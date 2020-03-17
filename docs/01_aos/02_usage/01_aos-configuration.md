---
content_title: Aos Configuration
---

The plugin-specific options can be configured using either CLI options or a configuration file, `config.ini`. Aos-specific options can only be configured from the command line. All CLI options and `config.ini` options can be found by running `aos --help` as shown above.

Each `config.ini` option has a corresponding CLI option. However, not all CLI options are available in `config.ini`. For instance, most plugin-specific options that perform actions are not available in `config.ini`, such as `--delete-state-history` from `state_history_plugin`.

For example, the CLI option `--plugin arisen::chain_api_plugin` can also be set by adding `plugin = arisen::chain_api_plugin` in `config.ini`.

## `config.ini` location

The default `config.ini` can be found in the following folders:
- Mac OS: `~/Library/Application Support/arisen/aos/config`
- Linux: `~/.local/share/arisen/aos/config`

A custom `config.ini` file can be set by passing the `aos` option `--config path/to/config.ini`.

## Aos Example

The example below shows a typical usage of `aos` when starting a block producing node:

```sh
aos --replay-blockchain \
  -e -p arisen \
  --plugin arisen::producer_plugin  \
  --plugin arisen::chain_api_plugin \
  --plugin arisen::http_plugin      \
  >> aos.log 2>&1 &
```

```sh
aos \
  -e -p arisen \
  --data-dir /users/mydir/arisen/data     \
  --config-dir /users/mydir/arisen/config \
  --plugin arisen::producer_plugin      \
  --plugin arisen::chain_plugin         \
  --plugin arisen::http_plugin          \
  --plugin arisen::state_history_plugin \
  --contracts-console   \
  --disable-replay-opts \
  --access-control-allow-origin='*' \
  --http-validate-host=false        \
  --verbose-http-errors             \
  --state-history-dir /shpdata \
  --trace-history              \
  --chain-state-history        \
  >> aos.log 2>&1 &
```

The above `aos` command starts a producing node by:

* enabling block production (`-e`)
* identifying itself as block producer "arisen" (`-p`)
* setting the blockchain data directory (`--data-dir`)
* setting the `config.ini` directory (`--config-dir`)
* loading plugins `producer_plugin`, `chain_plugin`, `http_plugin`, `state_history_plugin` (`--plugin`)
* passing `chain_plugin` options (`--contracts-console`, `--disable-replay-opts`)
* passing `http-plugin` options (`--access-control-allow-origin`, `--http-validate-host`, `--verbose-http-errors`)
* passing `state_history` options (`--state-history-dir`, `--trace-history`, `--chain-state-history`)
* redirecting both `stdout` and `stderr` to the `aos.log` file
* returning to the shell by running in the background (&)
