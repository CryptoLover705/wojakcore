// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The WojakCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_MINER_H
#define BITCOIN_MINER_H

#include "core.h"
#include "wallet.h"

/** Run the miner threads */
void GenerateBitcoins(bool fGenerate, CWallet* pwallet);
/** Generate a new block, without valid proof-of-work */
/** Generate a new block, without valid proof-of-work */
class BlockAssembler
{
public:
    BlockAssembler();
    CBlockTemplate* CreateNewBlock(CReserveKey& reservekey);
    
private:
    // Configuration
    unsigned int nBlockMaxSize;
    unsigned int nBlockPrioritySize;
    unsigned int nBlockMinSize;

    // Internal methods can be added here as we refactor further
};

CBlockTemplate* CreateNewBlock(CReserveKey& reservekey);
/** Modify the extranonce in a block */
void IncrementExtraNonce(CBlock* pblock, CBlockIndex* pindexPrev, unsigned int& nExtraNonce);
/** Do mining precalculation */
void FormatHashBuffers(CBlock* pblock, char* pmidstate, char* pdata, char* phash1);
/** Check mined block */
bool CheckWork(CBlock* pblock, CWallet& wallet, CReserveKey& reservekey);
/** Base sha256 mining transform */
void SHA256Transform(void* pstate, void* pinput, const void* pinit);

#endif // BITCOIN_MINER_H
