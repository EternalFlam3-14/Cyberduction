#ifndef GAME_H
#define GAME_H
#include "vault.h"
#include "storage.h"

class Game_C
{
    friend class cereal::access;
public:

    Game_C() {;};

    void add_Vault();
    void add_Vault(Vault_C inVault);

private:

    std::shared_ptr<Vault_C> Vault;

};

#endif