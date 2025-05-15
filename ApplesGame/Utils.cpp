#include "Utils.h"

namespace ApplesGame
{
	void SelectionSort(std::map<std::string, int>& map)
	{
		for (int i = 0; i < map.size() - 1; ++i) {
			// Assume the current position holds
			// the minimum element
			int min_idx = i;

			// Iterate through the unsorted portion
			// to find the actual minimum
			for (int j = i + 1; j < map.size(); ++j) {
				std::pair<const std::string, int>& min_idx_element = *std::next(map.begin(), min_idx);
				std::pair<const std::string, int>& jth_element = *std::next(map.begin(), j);
				if (jth_element.second > min_idx_element.second) {
					// Update min_idx if a smaller
					// element is found
					min_idx = j;
				}
			}

			// Move minimum element to its
			// correct position
			std::pair<std::string, int> ith_element = *std::next(map.begin(), i);
			std::pair<std::string, int> min_idx_element = *std::next(map.begin(), min_idx);

			std::pair<const std::string, int> temp = _STD move(ith_element);
			ith_element = _STD move(min_idx_element);
			min_idx_element = _STD move(temp);
		}
	}
}