#include <netsess/NetTypes.hpp>

namespace libnetwork {

    KeyValue::KeyValue(const std::string& key, const std::string& value) : key(key), value(value) {}

    UrlParameters::UrlParameters(const std::vector<KeyValue>& initial) : UrlParameters(UrlParameters(), initial) {}

    UrlParameters::UrlParameters(const UrlParameters& copy, const std::vector<KeyValue>& expanded) {
        _params = copy._params;
        if (!_params.empty()) {
            _params += "&";
        }
        for (auto& pair : expanded) {
            _params += pair.key;
            _params += "=";
            _params += pair.value;
            _params += "&";
        }
        if (!_params.empty()) {
            _params.resize(_params.size() - 1);
        }
    }

    UrlParameters UrlParameters::expand_copy(const std::vector<KeyValue>& added) const {
        return UrlParameters(*this, added);
    }

    std::string UrlParameters::apply(const std::string& url) const {
        std::string out = url + "?";
        out += _params;
        return out;
    }

    std::string UrlParameters::get() const {
        return _params;
    }

    bool UrlParameters::empty() const {
        return _params.empty();
    }

    JsonObject parse_json(std::string_view from) {
        return boost::json::parse(from).as_object();
    }
};
