#ifndef GAME_H
#define GAME_H
#include "vault.h"

class Game_C
{
public:

    Game_C() {;};

    void add_Vault();
    void add_Vault(Vault_C inVault);

private:

    std::shared_ptr<Vault_C> Vault;

};

#endif