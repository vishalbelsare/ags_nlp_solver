/*
Copyright (C) 2018 Sovrasov V. - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 * You should have received a copy of the MIT license with
 * this file. If not visit https://opensource.org/licenses/MIT
*/

#include "intervals_queue.hpp"

using namespace ags;

SingleIntervalsQueue::SingleIntervalsQueue() {}

bool SingleIntervalsQueue::empty() const
{
  return mQueue.empty();
}

Interval* SingleIntervalsQueue::pop(bool is_local)
{
  NLP_SOLVER_ASSERT(!is_local, "Trying to get local R from the single queue");
  auto ret_val = mQueue.top();
  mQueue.pop();
  return ret_val;
}

void SingleIntervalsQueue::push(Interval* i)
{
  mQueue.push(i);
}

void SingleIntervalsQueue::clear()
{
  mQueue = std::priority_queue<Interval*, std::vector<Interval*>, CompareByR>();
}
