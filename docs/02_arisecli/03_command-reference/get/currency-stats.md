## Description
Retrieve the stats of for a given currency

## Positional Parameters
`contract` _TEXT_  - The contract that operates the currency

`symbol` _TEXT_ - The symbol for the currency if the contract operates multiple currencies
## Options
There are no options for this subcommand
## Example
Get stats of the RIX token from the arisen.token contract. 

```sh
arisecli get currency stats arisen.token RIX
```
```json
{
  "RIX": {
    "supply": "1000000000.0000 RIX",
    "max_supply": "10000000000.0000 RIX",
    "issuer": "arisen"
  }
}
```
