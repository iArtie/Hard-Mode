#include <Geode/modify/OptionsLayer.hpp>
#include "../main.cpp"

using namespace geode::prelude;

class $modify(OptionsLayer) {

    void onAccount(CCObject*) {

        auto array = CCArray::create();


        array->addObject(DialogObject::create(
            "Darkness",
            tr(
                "<cp>No puedes</c> acceder a <co>tu cuenta</c>... <d60> <s200> <cr>NO</c></s><s200> <cr>TE</c></s><s200><cr> LO</c></s><s200> <cr>DEJARE</c></s><s200> <cr>TAN</c></s><s200> <cr>FACIL.</c></s>",
                "<cp>You cannot</c> access <co>your account</c>... <d60> <s200> <cr>I</c></s><s200> <cr>WON'T</c></s><s200><cr> LET</c></s><s200> <cr>YOU</c></s><s200> <cr>OFF</c></s><s200> <cr>EASILY.</c></s>"
            ).c_str(),
            15, 1, false, { 255, 255, 255 }
        ));

        auto accDialog = DialogLayer::createDialogLayer(nullptr, array, 2);
        accDialog->setZOrder(103);
        accDialog->animateInRandomSide();

        CCScene::get()->addChild(accDialog);

    }
};
