## Goal

Transfer token created by arisen.token contract

## Before you begin

* Install the currently supported version of `arisecli`

* You are going to transfer a token created by arisen.token contract and arisen.token contract has been deployed on the network which you are connected to

* Understand the following:
  * What is a transaction
  * Token transfers are irrevertable 

## Steps

Assume you would like to transfer `0.0001 RSN` token to an account called `bob` from an account called `alice`, execute the following:

```sh
arisecli transfer alice bob "0.0001 RSN" "Hodl!" -p alice@active
```
