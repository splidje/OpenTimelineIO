#include "opentimelineio/linearTimeWarp.h"

namespace opentimelineio { namespace OPENTIMELINEIO_VERSION  {
    
LinearTimeWarp::LinearTimeWarp(std::string const& name,
                               std::string const& effect_name,
                               double time_scalar,
                               AnyDictionary const& metadata)
    : Parent(name, effect_name, metadata),
      _time_scalar(time_scalar) {
}

LinearTimeWarp::~LinearTimeWarp() {
}

bool LinearTimeWarp::read_from(Reader& reader) {
    return reader.read("time_scalar", &_time_scalar) &&
        Parent::read_from(reader);
}

void LinearTimeWarp::write_to(Writer& writer, visited_objects_t visited_objects) const {
    Parent::write_to(writer, visited_objects);
    writer.write("time_scalar", _time_scalar, visited_objects);
}

} }
