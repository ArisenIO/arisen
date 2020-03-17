# login_plugin

## Description

The `login_plugin` supports the concept of applications authenticating with the ARISEN blockchain. The `login_plugin` API allows an application to verify whether an account is allowed to sign in order to satisfy a specified authority.

## Usage

```console
# config.ini
plugin = arisen::login_plugin
[options]
```
```sh
# command-line
aos ... --plugin arisen::login_plugin [options]
```

## Options

These can be specified from both the `aos` command-line or the `config.ini` file:

```console
Config Options for arisen::login_plugin:
  --max-login-requests arg (=1000000)   The maximum number of pending login 
                                        requests
  --max-login-timeout arg (=60)         The maximum timeout for pending login 
                                        requests (in seconds)
```

## Dependencies

* [`chain_plugin`](../chain_plugin/index.md)
* [`http_plugin`](../http_plugin/index.md)

### Load Dependency Examples

```console
# config.ini
plugin = arisen::chain_plugin
[options]
plugin = arisen::http_plugin 
[options]
```
```sh
# command-line
aos ... --plugin arisen::chain_plugin [options]  \
           --plugin arisen::http_plugin [options]
```
