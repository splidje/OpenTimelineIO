__doc__ = """OpenTimelineIO Adobe Premiere Project Adapter"""

from xml.etree import ElementTree as ET
import gzip

import opentimelineio as otio


class AdobePremiereProjectParseError(otio.exceptions.OTIOError):
    pass

def read_from_file(filepath):
    try:
        input_str = gzip.GzipFile(filepath).read()
    except gzip.BadGzipFile:
        input_str = open(filepath).read()
    return read_from_string(input_str)


def read_from_string(input_str):
    try:
        root = ET.fromstring(input_str)
    except ET.ParseError:
        raise AdobePremiereProjectParseError("Data is neither XML nor gzipped XML.")

    collection = otio.schema.SerializableCollection()

    return collection
