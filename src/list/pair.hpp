//
// Created by chiel on 06/09/16.
//

#ifndef PO2_METALIB_PAIR_HPP
#define PO2_METALIB_PAIR_HPP

template<typename f, typename s>
struct pair {
	using first = f;
	using second = s;
	using r = pair<f, s>;
};

#endif //PO2_METALIB_PAIR_HPP
