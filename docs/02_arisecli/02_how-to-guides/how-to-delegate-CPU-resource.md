## Goal

Delegate resource for an account or application

## Before you begin

* Install the currently supported version of `cleos`

* Ensure the reference system contracts from `arisen.contracts` repository is deployed and used to manage system resources

* Understand the following:
  * What is an account
  * What is network bandwidth
  * What is CPU bandwidth

## Steps

Delegate 0.01 SYS CPU bandwidth from `bob` to `alice`

```sh
cleos system delegatebw bob alice "0.01 SYS" "0 SYS"
```

You should see something below:

```console
executed transaction: 5487afafd67bf459a20fcc2dbc5d0c2f0d1f10e33123eaaa07088046fd18e3ae  192 bytes  503 us
#         arisen <= arisen::delegatebw            {"from":"bob","receiver":"alice","stake_net_quantity":"0.0000 SYS","stake_cpu_quanti...
#   arisen.token <= arisen.token::transfer        {"from":"bob","to":"arisen.stake","quantity":"0.0010 EOS","memo":"stake bandwidth"}
#  bob <= arisen.token::transfer        {"from":"bob","to":"arisen.stake","quantity":"0.0010 SYS","memo":"stake bandwidth"}
#   arisen.stake <= arisen.token::transfer        {"from":"bob","to":"arisen.stake","quantity":"0.0010 SYS","memo":"stake bandwidth"}
```
