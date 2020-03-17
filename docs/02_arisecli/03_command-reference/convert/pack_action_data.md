## Description
From json action data to packed form

## Positionals
- `account` _TEXT_ - The name of the account that hosts the contract
- `name` _TEXT_ - The name of the function that's called by this action
- `unpacked_action_data` _TEXT_ - The action data expressed as json

## Options

- `-h,--help` - Print this help message and exit

## Usage
```sh
 arisecli convert pack_action_data arisen unlinkauth '{"account":"test1", "code":"test2", "type":"arisenarisen"}'
```

## Output


```console
000000008090b1ca000000000091b1ca000075982aea3055
```
