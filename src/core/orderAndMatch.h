#ifndef __ORDER_AND_MATCH_H__
#define __ORDER_AND_MATCH_H__

using namespace std;

class OrderAndMatch
{
    int hashSeed;
    unsigned char *piList;
    unsigned char *tauList;
public:
    OrderAndMatch(int hashSeed, unsigned char piList[], unsigned char tauList[]) : 
        hashSeed(hashSeed), piList(piList), tauList(tauList) {}
};

#endif