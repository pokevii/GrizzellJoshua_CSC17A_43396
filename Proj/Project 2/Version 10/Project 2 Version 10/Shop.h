/*! Contains all of the items used in the shop. */
#ifndef SHOP_H
#define SHOP_H
#include "Item.h"
#include "PlayerData.h"

class Shop : Item{
  protected:
    static Item item[9];
  public:
    friend class PlayerData;
    //Constructor defined in Shop.cpp
    Shop(bool isNew);

    //Inline function defined in Shop.cpp
    PlayerData prnShop(PlayerData pd);

    //Virtual function inherited from Item.h defined in Shop.cpp.
};

#endif