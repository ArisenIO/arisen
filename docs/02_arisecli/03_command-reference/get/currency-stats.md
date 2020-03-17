## Description
Retrieve the stats of for a given currency

## Positional Parameters
`contract` _TEXT_  - The contract that operates the currency

`symbol` _TEXT_ - The symbol for the currency if the contract operates multiple currencies
## Options
There are no options for this subcommand
## Example
Get stats of the RSN token from the arisen.token contract. 

```sh
arisecli get currency stats arisen.token RSN
```
```json
{
  "RSN": {
    "supply": "1000000000.0000 RSN",
    "max_supply": "10000000000.0000 RSN",
    "issuer": "arisen"
  }
}
```
