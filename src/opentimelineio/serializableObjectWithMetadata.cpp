#include "opentimelineio/serializableObjectWithMetadata.h"

namespace opentimelineio { namespace OPENTIMELINEIO_VERSION  {
    
SerializableObjectWithMetadata::SerializableObjectWithMetadata(std::string const& name,
                                                               AnyDictionary const& metadata)
    : _name(name),
      _metadata(metadata)
{
}

SerializableObjectWithMetadata::~SerializableObjectWithMetadata() {
}

bool SerializableObjectWithMetadata::read_from(Reader& reader) {
    return reader.read_if_present("metadata", &_metadata) &&
        reader.read_if_present("name", &_name) &&
        SerializableObject::read_from(reader);
}

void SerializableObjectWithMetadata::write_to(Writer& writer, visited_objects_t visited_objects) const {
    SerializableObject::write_to(writer, visited_objects);
    writer.write("metadata", _metadata, visited_objects);
    writer.write("name", _name, visited_objects);
}

} }
