## Description
status of existing connection

**Command**

```sh
arisecli net status
```
**Output**

```console
Usage: arisecli net status host

Positionals:
  host TEXT                   The hostname:port to query status of connection
```

Given, a valid, existing `hostname:port` parameter the above command returns a json response looking similar to the one below:

```
{
  "peer": "hostname:port",
  "connecting": false/true,
  "syncing": false/true,
  "last_handshake": {
    ...
  }
}
```

The `last_handshake` structure is explained in detail in the [Network Peer Protocol](https://developers.rsn.io/welcome/latest/protocol/network_peer_protocol#421-handshake-message) documentation section.