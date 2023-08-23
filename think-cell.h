#include <map>

template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K, V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
		: m_valBegin(val)
	{
		//m_map.insert({1, 'B'});
		//m_map.insert({3, 'A' });
	}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign(K const& keyBegin, K const& keyEnd, V const& val) {
		if (!(keyBegin < keyEnd)) {
			return;
		}
		if (val == m_valBegin) {
			if (m_map.size() == 0) {
				// do nothing
			} else { 
				auto itBegin = m_map.lower_bound(keyBegin);
				if (itBegin == m_map.end()) {
					m_map.insert({ keyBegin, val });
				} else if (itBegin != m_map.begin()) {
					m_map.insert({ keyBegin, val });
				}
			}
			return;
		}

		V lastVal = m_valBegin;
		auto rItr = m_map.rbegin();
		if (rItr != m_map.rend()) {
			lastVal = rItr->second;
		}
	
		if (val != lastVal) {
			m_map.insert({ keyBegin, val });
		}
	}

	// look-up of the value associated with key
	V const& operator[](K const& key) const {
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin()) {
			return m_valBegin;
		}
		else {
			return (--it)->second;
		}
	}
};
