# WojakCoin v1.0.1 - Security Update Release Notes

**Release Date:** November 29, 2025  
**Type:** Security Update - **HIGHLY RECOMMENDED**

---

## What's New

This release adds critical security protections against blockchain attacks and fixes several bugs. All node operators, miners, and exchanges are strongly encouraged to upgrade immediately.

---

## 🛡️ Security Improvements

### 🚨 Critical Vulnerabilities Patched

*   **Fixed CVE-2018-17144 (Inflation / Double Spend Bug):**
    *   **Severity:** Critical
    *   **Description:** Patched a vulnerability that could allow a miner to inflate the coin supply by including duplicate inputs within the same block. The node now strictly enforces that no two inputs in a block spend the same previous output.
*   **Fixed CVE-2013-5700 (Bloom Filter Crash):**
    *   **Severity:** High (DoS)
    *   **Description:** Fixed a divide-by-zero error in the Bloom Filter logic that could allow a remote attacker to crash the node using a malformed request.

### 🔒 Network Security Enhancements

*   **Maximum Reorganization Depth Protection:**
    *   **Mainnet:** 20 blocks (matches COINBASE_MATURITY)
    *   **Testnet:** 40 blocks
    *   **Regtest:** Unlimited
    *   **Rationale:** Limits how far back the chain can be reorganized, protecting against 51% attacks attempting to rewrite history.

*   **Minimum Chain Work Validation:**
    *   **Mainnet:** `0x10000`
    *   **Testnet:** `0x100`
    *   **Regtest:** `0x0`
    *   **Rationale:** Nodes reject chains without sufficient cumulative proof-of-work, preventing eclipse attacks with fake low-work chains.

*   **New Checkpoints Added:**
    *   Added checkpoints for blocks 500 and 600 to prevent reorganization past trusted blocks.

---

## 🐛 Bug Fixes & Enhancements

*   **Coin Control:**
    *   Fixed the "Display coin control features" option in the Settings dialog. It now correctly saves the user's preference and toggles the Coin Control features in the Send dialog.
*   **Subtract Fee From Amount:**
    *   Fixed a logic error where sending the full balance with "Subtract Fee" enabled would cause an "Insufficient funds" error.
*   **Rebranding:**
    *   Completed full rebranding from "Linkcoin" to "WojakCoin" (WJK) across all UI dialogs and tooltips.

---

## Technical Changes

**Files Modified:**
*   `src/main.cpp`: Added duplicate input check (CVE-2018-17144) and chain work validation.
*   `src/bloom.cpp`: Added divide-by-zero check (CVE-2013-5700).
*   `src/chainparams.cpp`: Set network-specific minimum chain work values.
*   `src/checkpoints.cpp`: Added new checkpoints.
*   `src/qt/optionsmodel.cpp`: Fixed Coin Control setting persistence.
*   `src/qt/walletmodel.cpp`: Fixed Subtract Fee balance validation.
*   `src/clientversion.h`: Version bump to 1.0.1.0.

---

## Upgrade Instructions

### Backup First
```bash
# Backup your wallet
cp ~/.wojakcoin/wallet.dat ~/wojak-wallet-backup-$(date +%Y%m%d).dat
```

### Build and Install
```bash
cd /path/to/WOJAKCOIN
git pull  # or download latest release
make clean
qmake && make -j$(nproc)
```

### Restart Node
```bash
# Stop old version
wojakcoin-cli stop

# Wait for shutdown
sleep 5

# Start new version
./wojakcoind -daemon

# Verify version
wojakcoin-cli getinfo | grep version
# Should show: "version" : 100100
```

---

## Compatibility

✅ **Fully backwards compatible**
*   Old nodes can sync with new nodes.
*   No consensus rule changes (Soft Fork only for security strictness).
*   No hard fork.

⚠️ **Chain selection differences**
*   New nodes reject deep reorganizations (>20 blocks on mainnet).
*   New nodes reject low-work chains.
*   This is intentional security behavior.

---

## Support

**Issues:** GitHub Issues or Discord  
**Emergency:** If experiencing sync problems, report immediately  
**Community:** Join our Discord for real-time support

---

## Version History

*   **v1.0.1** (2025-11-29) - Security update: CVE patches, max reorg depth, min chain work, bug fixes.
*   **v1.0.0** (Previous) - Initial stable release.

---

## Checksums

**To be added after final release build**

Linux x64: `[TBD]`  
Windows: `[TBD]`  
macOS: `[TBD]`  
ARM: `[TBD]`
