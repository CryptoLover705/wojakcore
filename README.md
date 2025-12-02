# WOJAKCOIN (WJK)

WojakCoin is a decentralized cryptocurrency based on Bitcoin Core, featuring a fair launch, advanced difficulty adjustment, and enhanced security.

## 🚀 Network Information

### Official Resources
- **Network**: WojakCoin Mainnet
- **Ticker**: WJK
- **DNS Seed**: wojak-seed.s3na.xyz
- **P2P Port**: 20759
- **RPC Port**: 20760

### Seed Nodes
```
103.133.25.201:20759
159.223.90.59:20759
207.244.232.43:20759
```

## 📊 Emission Schedule

### Block Rewards by Era

| Era | Block Range | Reward | Blocks | Total Coins | Cumulative |
|-----|-------------|--------|--------|-------------|------------|
| 1 | 0 - 209,999 | 100 WJK | 210,000 | 21,000,000 | 21,000,000 |
| 2 | 210,000 - 419,999 | 50 WJK | 210,000 | 10,500,000 | 31,500,000 |
| 3 | 420,000 - 629,999 | 25 WJK | 210,000 | 5,250,000 | 36,750,000 |
| 4 | 630,000 - 839,999 | 12.5 WJK | 210,000 | 2,625,000 | 39,375,000 |
| 5+ | 840,000+ | Continues halving... | ∞ | ~2,625,000 | ~42,000,000 |

### Timeline Estimates (2-minute blocks)

| Milestone | Blocks | Time from Launch |
|-----------|--------|------------------|
| First Halving | 210,000 | ~291 days (~9.7 months) |
| Second Halving | 420,000 | ~583 days (~1.6 years) |
| Third Halving | 630,000 | ~875 days (~2.4 years) |
| 90% Mined | ~1,050,000 | ~1,458 days (~4 years) |

## 🛠️ Build Instructions

**Recommended Environment**: Debian 7 (Wheezy)
This codebase is optimized for older Linux distributions. We strongly recommend using Debian 7 for the most stable build experience.

### Linux (Debian 7 Recommended)

1. **Install Dependencies**
   ```bash
   apt-get update
   apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils python3
   # Install MinGW for cross-compilation if needed
   apt-get install g++-mingw-w64-x86-64
   ```

2. **Build Dependencies**
   ```bash
   cd depends
   make HOST=x86_64-pc-linux-gnu
   cd ..
   ```

3. **Build Daemon and GUI**
   ```bash
   ./build.sh --linux
   ```

   Binaries will be available in:
   - `src/wojakcoind`
   - `wojakcoin-qt`

### Windows (Cross-compile from Debian 7)

1. **Build Dependencies**
   ```bash
   cd depends
   make HOST=x86_64-w64-mingw32
   cd ..
   ```

2. **Build Daemon and GUI**
   ```bash
   ./build.sh --windows
   ```

   Binaries will be available in:
   - `src/wojakcoind.exe`
   - `release/wojakcoin-qt.exe`

## 🔒 Security Features

- **Difficulty Adjustment**: DGW-style moving average (activates at block 1000).
- **Timestamp Protection**: 24-minute future limit, Median-time-past validation.
- **Money Supply Protection**: MAX_MONEY validation on rewards.
- **Network Security**: Multiple seed nodes, DNS seed for redundancy.

## 🎓 For Miners

- **Algorithm**: SHA-256
- **Block Time**: 2 minutes
- **Initial Reward**: 100 WJK
- **Difficulty**: Adjusts every block (after block 1000)
- **Maturity**: 20 blocks (40 minutes)

### Mining Configuration
```conf
gen=1
genproclimit=-1
miningaddress=address
```

## License

WojakCoin is released under the terms of the MIT license. See [COPYING](COPYING) for more information or see https://opensource.org/licenses/MIT.
