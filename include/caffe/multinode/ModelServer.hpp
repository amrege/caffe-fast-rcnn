#ifndef CAFFE_MULTINODE_MODEL_SERVER_HPP_
#define CAFFE_MULTINODE_MODEL_SERVER_HPP_

#include <string>
#include <vector>
#include "caffe/internode/configuration.hpp"
#include "caffe/solver.hpp"

namespace caffe {

template <typename Dtype>
class ModelServer : public internode::Waypoint::Handler {
  shared_ptr<internode::Daemon> daemon;
  shared_ptr<Solver<Dtype> > solver;
  SolverParameter param_;
  shared_ptr<internode::MultiWaypoint> waypoint;

  SolverParameter prepare_model();
  BlobShape blob_shape_by_name(string name);
 public:
  ModelServer(shared_ptr<Solver<Dtype> >,
              string bind_address,
              string ignored_address,
              int ignored_threads);
  void run();

  virtual void received(char* data, size_t size, internode::Waypoint*);
};

}  // namespace caffe

#endif  // CAFFE_MULTINODE_MODEL_SERVER_HPP_

