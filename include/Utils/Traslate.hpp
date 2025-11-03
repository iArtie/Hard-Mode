#include <string>
#include <string_view>
#include <Geode/Geode.hpp>
#include <fmt/chrono.h>

using namespace geode::prelude;

class Traslate {
public:
	static std::string tr(const std::string& es, const std::string& en);
};
