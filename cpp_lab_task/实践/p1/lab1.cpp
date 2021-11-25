#include <iostream>
#include <queue>
#include <ctime>
#include <unordered_map>
#include <list>
#include <fstream>

namespace lab1 {
    class cache {
    public:
        cache(int cacheSize) {
            cache::cacheSize = cacheSize;
        }

        int cachemiss = 0;
        int cacheget = 0;

        int get(int key) {
            if (hashmap.find(key) != hashmap.end()) {
                cacheget++;
                updateList(key);
                return hashmap[key];
            }
            else {
                cachemiss++;
                if ((int)hashmap.size() == cacheSize) {
                    hashmap.erase(cachelist.back());
                    cachelist.pop_back();
                }
                hashmap.insert({ key, readMemory(key) });
                cachelist.emplace_front(key);
               
            }
            return hashmap[key];
        }

        int readMemory(int key) {
            int result;
            std::ifstream infile("memory", std::ios::in|std::ios::binary);
            if (!infile.is_open())
                throw std::runtime_error("cannot open file");
            infile.seekg(key*sizeof(int), std::ios::beg);
            infile.read((char*)&result, sizeof(int));
            infile.close();
            return result;
        }

        void updateList(int key) {
            if (key == cachelist.front())
                return;
            // only put the element to first, not delete
            for (auto i = cachelist.begin(); i != cachelist.end(); ++i) {
                if (*i == key) {
                    cachelist.erase(i);
                    cachelist.emplace_front(key);
                    return;
                }
            }
            throw std::runtime_error("cache not found");
        }

    private:
        int cacheSize;
        std::unordered_map<int, int> hashmap;
        std::list<int> cachelist;
    };

    void initMatrix(int n) {
        std::srand(std::time(nullptr));
        std::ofstream outfile("memory", std::ios::trunc|std::ios::binary);
        //Matrix C, A, B
        for (int x = 0; x < 3 * n * n; ++x) {
            int ri = rand() % 10;
            outfile.write((char*)&ri, sizeof(int));
        }
        outfile.close();
    }

    void multiple(int n) {
        int cacheSize = 50;
        int startC = 0;
        cache cacheC(cacheSize);
        int startA = n * n;
        cache cacheA(cacheSize);
        int startB = 2 * n * n;
        cache cacheB(cacheSize);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    cacheC.get(startC + i * n + j);
                    cacheA.get(startA + i * n + k);
                    cacheB.get(startB + k * n + j);
                }
            }
        }
        printf("C: cache miss: %d, cache total: %d\n", cacheC.cachemiss, cacheC.cacheget + cacheC.cachemiss);
        printf("A: cache miss: %d, cache total: %d\n", cacheA.cachemiss, cacheA.cacheget + cacheA.cachemiss);
        printf("B: cache miss: %d, cache total: %d\n", cacheB.cachemiss, cacheB.cacheget + cacheB.cachemiss);

    }
}// namespace lab1

int main() {
    int n = 10;
    lab1::initMatrix(n);
    lab1::multiple(n);
}