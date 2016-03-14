The building and improving of the AI progressed as follows:

Initial building: The AI randomly selects a move from a list of possible moves
and plays it. This was enough to beat SimplePlayer about (surprisingly enough)
50% of the time.

Improvement 1: If a corner move was available to the AI, it was taken. This
beat SimplePlayer about 75% of the time and lost almost consistently to
ConstantTimePlayer.

Improvement 2: The AI selects the move that results in the largest gain in score
This consistently beats SimplePlayer (>90% of the time) and loses to
ConstantTimePlayer about half the time.

Improvement 3: Combining Improvements 1 and 2, the AI now selects the move
resulting in the maximum increase in score with the following multipliers on
the increase:
x3 for a corner play
x2 for an edge play
x-2 for an edge piece adjacent to the corner
x-3 for a non-edge piece diagonally adjacent to a corner
This beats both SimplePLayer and ConstantTimePlayer consistently, but loses
consistently and deterministically to BetterPlayer.

Improvement 3a: Minimax consideration at depth 2 was implemented. Applying
this minimax to the AI in-game beats SimplePlayer, but less consistently than
the heuristic of improvement 3.

Improvement Attempt: Since minimax and heuristic both did well against
ConstantTimePlayer but lost against BetterPlayer, I wondered if a combination
of the two could beat BetterPlayer. I implemented a combination by applying
heuristic weights to each score before consideration in minimax. The result
was actually a worse AI that lost half the time to ConstantTimePlayer. Thus,
I chose to keep my AI at the heuristic level, which should be enough to beat
some simplistic AI's such as ConstantTimePlayer.

NOTE: crynet (the AI) should be run with testingminimax variable as false.
