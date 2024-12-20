#include <mrs_uav_state_estimators/estimators/state/state_generic.h>

namespace vins_mono
{

const char estimator_name[] = "vins_mono";
const bool is_core_plugin = false;

class VinsMono : public mrs_uav_state_estimators::StateGeneric {
public:
  VinsMono() : mrs_uav_state_estimators::StateGeneric(estimator_name, is_core_plugin) {
  }

  ~VinsMono(void) {
  }
};

}  // namespace vins_mono

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(vins_mono::VinsMono, mrs_uav_managers::StateEstimator)

