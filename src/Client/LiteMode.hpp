#pragma once

#include "Module.hpp"
#include <string>

// Modo "lite": el menu solo conserva unas pocas funciones.
// Todo lo demas queda oculto en el menu y desactivado.
namespace qolmod::lite
{
    // IDs de los modulos principales que se quedan
    inline bool isKeptID(const std::string& id)
    {
        return id == "noclip"
            || id == "show-hitboxes"
            || id == "wave-trail-size"
            || id == "hide-btn";
    }

    // las opciones (hijos) cuentan como parte de su modulo principal
    inline Module* getRoot(Module* mod)
    {
        while (mod && mod->getParent())
            mod = mod->getParent();

        return mod;
    }

    inline bool isKept(Module* mod)
    {
        auto root = getRoot(mod);

        return root && isKeptID(root->getID());
    }

    // true si el modulo es de las categorias de hacks que se quitaron
    inline bool isRemoved(Module* mod)
    {
        auto root = getRoot(mod);

        if (!root || isKeptID(root->getID()))
            return false;

        auto cat = root->getCategory();
        auto slash = cat.find('/');

        if (slash != std::string::npos)
            cat = cat.substr(0, slash);

        return cat == "Level"
            || cat == "Cosmetic"
            || cat == "Universal"
            || cat == "Creator"
            || cat == "Shortcuts";
    }
}
