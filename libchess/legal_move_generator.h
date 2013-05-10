#ifndef LIBCHESS_LEGAL_MOVE_GENERATOR_H
#define LIBCHESS_LEGAL_MOVE_GENERATOR_H

#include <boost/shared_ptr.hpp>

#include "position.h"
#include "pseudo_legal_move_generator.h"

namespace chess {

class Position;

/**
 * \brief Enumerates legal moves in a given position.
 */
class LegalMoveGenerator : boost::noncopyable {
public:
    LegalMoveGenerator(const Position& position);
    ~LegalMoveGenerator();

    int __len__();
    bool __nonzero__();
    LegalMoveGenerator& __iter__();
    bool __contains__(const Move& move);

    Move next();
    Move python_next();
    bool has_more();

private:
    bool would_be_valid_if_pseudo_legal(const Move& move) const;

    Position* m_position;
    PseudoLegalMoveGenerator* m_pseudo_legal_moves;
    int m_len;
    int m_current;
};

} // namespace chess

#endif // LIBCHESS_LEGAL_MOVE_GENERATOR_H