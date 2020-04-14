#include <base/Sensor.hh>
#include <ApolloSM/ApolloSM.hh>

class ApolloMonitor : public Sensor {

public:
  ApolloMonitor(std::string const & connectionFile,
		std::string const & userBase,
		std::string const & tableName,
		int level);
  virtual int Report();
  virtual float GetVal();
private:
  void SetSensors();
  std::string base;
  ApolloSM * SM;
};
