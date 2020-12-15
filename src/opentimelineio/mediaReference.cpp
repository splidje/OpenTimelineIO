#include "opentimelineio/mediaReference.h"

namespace opentimelineio { namespace OPENTIMELINEIO_VERSION  {
    
MediaReference::MediaReference(std::string const& name,
                               optional<TimeRange> const& available_range,
                               AnyDictionary const& metadata)
    : Parent(name, metadata),
      _available_range(available_range) {
}

MediaReference::~MediaReference() {
}


bool MediaReference::is_missing_reference() const {
    return false;
}

bool MediaReference::read_from(Reader& reader) {
    return reader.read_if_present("available_range", &_available_range) &&
        Parent::read_from(reader);
}

void MediaReference::write_to(Writer& writer, visited_objects_t visited_objects) const {
    Parent::write_to(writer, visited_objects);
    writer.write("available_range", _available_range, visited_objects);
}

} }
