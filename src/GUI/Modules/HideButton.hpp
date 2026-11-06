#pragma once

#include "../../Client/Module.hpp"
#include <Utils.hpp>

using namespace geode::prelude;

class HideButton : public Module
{
    public:
        MODULE_SETUP(HideButton)
        {
            setName("Hide Button");
            setID("hide-btn");
            setCategory("Config/Button");
            setDescription("Hides the button to open the mod");
            setDefaultEnabled(true);

            #ifdef GEODE_IS_MOBILE
            // en movil el boton se muestra por defecto, pero se puede ocultar
            setDefaultEnabled(false);
            #endif
        }
};

SUBMIT_HACK(HideButton);
