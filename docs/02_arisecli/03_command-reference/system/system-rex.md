## Description

Actions related to BEX (the resource exchange).

## Subcommands

- [deposit](system-bex-deposit) - Deposit into owner's BEX fund by transfering from owner's liquid token balance
- [withdraw](system-bex-withdraw) - Withdraw from owner's BEX fund by transfering to owner's liquid token balance
- [buyrex](system-bex-buyrex) - Buy BEX using tokens in owner's BEX fund
- [lendrex](system-bex-lendrex)  - Deposit tokens to BEX fund and use the tokens to buy BEX
- [unstaketorex](system-bex-unstaketorex) - Buy BEX using staked tokens
- [sellrex](system-bex-sellrex) - Sell BEX tokens
- [cancelrexorder](system-bex-cancelrexorder) - Cancel queued BEX sell order if one exists
- [mvtosavings](system-bex-mvtosavings) - Move BEX tokens to savings bucket
- [mvfromsavings](system-bex-mvfromsavings) - Move BEX tokens out of savings bucket
- [rentcpu](system-bex-rentcpu) - Rent CPU bandwidth for 30 days
- [rentnet](system-bex-rentnet) - Rent Network bandwidth for 30 days
- [fundcpuloan](system-bex-fundcpuloan) - Deposit into a CPU loan fund
- [fundnetloan](system-bex-fundnetloan) - Deposit into a Network loan fund
- [defundcpuloan](system-bex-defundcpuloan) - Withdraw from a CPU loan fund
- [defundnetloan](system-bex-defundnetloan) - Withdraw from a Network loan fund
- [consolidate](system-bex-consolidate) - Consolidate BEX maturity buckets into one that matures in 4 days
- [updaterex](system-bex-updaterex) - Update BEX owner vote stake and vote weight
- [rexexec](system-bex-rexexec) - Perform BEX maintenance by processing expired loans and unfilled sell orders
- [closerex](system-bex-closerex) - Delete unused BEX-related user table entries
