#pragma once
#include <atomic>
#include <chrono>
#include <deque>
#include <cmath>
#include <thread>
#include "defs.h"
#include "eval.h"
#include "bitboard.h"
#include "movepick.h"
#include "movegen.h"
#include "timeman.h"
#include "transpositionTable.h"




#define ASPIRATION_DELTA 15


struct BestMoveInfo {
    MOVE move;
    int eval;

    BestMoveInfo(uint16_t move, int eval) : move(move), eval(eval) {}
};

struct PrintInfo {
    uint64_t nodes;
    uint64_t nps;
    int depth;
    int seldepth;
    int score;
    int eval;
    int totalTime;
    int hashUsage;
    std::string pv;
};


extern std::atomic<bool> exit_thread_flag;
extern int totalTime;
extern bool canPrintInfo;
extern ThreadSearch *thread;
extern int nThreads;

extern void cleanUpSearch();
extern void setNumThreads(const int numThreads);
extern void setTTSize(int hashSize);
extern void clearTT();
extern void beginSearch(Bitboard &b, int depth, int wtime, int btime, int winc, int binc, int movesToGo, bool analysis);
extern void InitLateMoveArray();
extern uint64_t getTotalNodesSearched();
extern int qsearch(Bitboard &b, ThreadSearch *th, int depth, int alpha, int beta, int ply);
