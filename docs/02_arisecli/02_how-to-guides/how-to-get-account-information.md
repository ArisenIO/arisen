## Goal

Query infomation of an ARISEN account

## Before you begin

* Install the currently supported version of `arisecli`

* Understand the following:
  * What is an account

## Steps

Execute the command below:

```sh
arisecli get account ACCOUNT_NAME
```

This should produce similar output as below:

```console
created: 2018-06-01T12:00:00.000
privileged: true
permissions:
     owner     1:    1 RSN7yTxtZr3EKN4S8pE1rrRHjYzXN3SnZCzq77zj4dzwFcrJC97jp
        active     1:    1 RSN7yTxtZr3EKN4S8pE1rrRHjYzXN3SnZCzq77zj4dzwFcrJC97jp
memory:
     quota:       unlimited  used:     3.004 KiB

net bandwidth:
     used:               unlimited
     available:          unlimited
     limit:              unlimited

cpu bandwidth:
     used:               unlimited
     available:          unlimited
     limit:              unlimited
```

[[info | Account Fields]]
| Depending on the ARISEN network you are connected, you might see different fields associated with an account. That depends on which system contract has been deployed on the network.
