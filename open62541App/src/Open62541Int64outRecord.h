/*
 * Copyright 2019 aquenos GmbH.
 * Copyright 2019 Karlsruhe Institute of Technology.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * This software has been developed by aquenos GmbH on behalf of the
 * Karlsruhe Institute of Technology's Institute for Beam Physics and
 * Technology.
 *
 * This software contains code originally developed by aquenos GmbH for
 * the s7nodave EPICS device support. aquenos GmbH has relicensed the
 * affected portions of code from the s7nodave EPICS device support
 * (originally licensed under the terms of the GNU GPL) under the terms
 * of the GNU LGPL version 3 or newer.
 */

#ifndef OPEN62541_EPICS_INT64OUT_RECORD_H
#define OPEN62541_EPICS_INT64OUT_RECORD_H

#include <int64outRecord.h>

#include "Open62541OutputRecord.h"

namespace open62541 {
namespace epics {

/**
 * Device support class for the int16out record.
 */
class Open62541Int64outRecord: public Open62541OutputRecord<::int64outRecord> {

public:

  /**
   * Creates an instance of the device support for the specified record.
   */
  Open62541Int64outRecord(::int64outRecord *record) :
      Open62541OutputRecord(record) {
    // We call this method here instead of the base constructor because it can
    // be (and is) overridden in child classes.
    validateRecordAddress();
  }

protected:

  UaVariant readRecordValue() {
    return readRecordValueGeneric(this->getRecord()->val,
        Open62541RecordAddress::DataType::int64);
  }

  void writeRecordValue(const UaVariant &value) {
    writeRecordValueGeneric(value, this->getRecord()->val);
  }

private:

  // We do not want to allow copy or move construction or assignment.
  Open62541Int64outRecord(const Open62541Int64outRecord &) = delete;
  Open62541Int64outRecord(Open62541Int64outRecord &&) = delete;
  Open62541Int64outRecord &operator=(const Open62541Int64outRecord &) = delete;
  Open62541Int64outRecord &operator=(Open62541Int64outRecord &&) = delete;

};

}
}

#endif // OPEN62541_EPICS_INT64OUT_RECORD_H
