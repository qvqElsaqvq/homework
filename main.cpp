#include "Engine.h"
#include "Helm.h"
#include "Manage.h"

int main() {
    int N; //命令数量
    std::cin >> N;
    int time, team, feature, param;
    char id;
    Manage pool(N);
    for(int i = 0; i < N; i++) {
        std::cin >> time >> id >> team >> feature >> param;
        pool.Read(time, id, team, feature, param);
    }
    return 0;
}