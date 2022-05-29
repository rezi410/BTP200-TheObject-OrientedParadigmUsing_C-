#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include <iostream>
#include "Patient.h"

namespace sdds {
   class TriagePatient : public Patient {
      char* m_symptoms;   //sysmptoms of triage patient
   public:
      TriagePatient();
      char type() const;
      std::ostream& csvWrite(std::ostream& ostr)const;
      std::istream& csvRead(std::istream& istr);
      std::ostream& write(std::ostream& ostr)const;
      std::istream& read(std::istream& istr);
      ~TriagePatient();




   };


}
#endif // !SDDS_TRIAGEPATIENT_H


