#include "Traslate.hpp"

std::string Traslate::tr(const std::string& es, const std::string& en) {
    auto lang = Mod::get()->getSettingValue<std::string>("language");
    return (lang == "English" ? en : es);
}
