## Description
Retrieve accounts which are servants of a given account 

## Info

**Command**

```sh
arisecli get servants
```
**Output**

```console
Usage: arisecli get servants account

Positionals:
  account TEXT                The name of the controlling account
```

## Command

```sh
arisecli get servants inita
```

## Output

```json
{
  "controlled_accounts": [
    "tester"
  ]
}
```
