#include "opentimelineio/effect.h"
#include "opentimelineio/missingReference.h"

namespace opentimelineio { namespace OPENTIMELINEIO_VERSION  {
    
Effect::Effect(std::string const& name,
               std::string const& effect_name,
               AnyDictionary const& metadata)
    : Parent(name, metadata),
      _effect_name(effect_name) {
}

Effect::~Effect() {
}

bool Effect::read_from(Reader& reader) {
    return reader.read("effect_name", &_effect_name) &&
        Parent::read_from(reader);
}

void Effect::write_to(Writer& writer, visited_objects_t visited_objects) const {
    Parent::write_to(writer, visited_objects);
    writer.write("effect_name", _effect_name, visited_objects);
}

} }
