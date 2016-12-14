##Analyzer Base Class
> Analyzer Base Class implementation can wait

As can be speculated, there will be multiple analyzers designed to facilitate decision making for players. It may be wise to device a base class and a set of interface for them all. A thought on my mind right now is something like:
Report Analyzer::analyze(const Information& info)

##Report Class
> Analyzer does the analytical work and Report elaborate on the conclusion that can be drawn from the analytical result. 

Putting all the analyzed result in a single data structure for future reference, so that I don't have to come up with the whole solution to the problem all at once, but can proceed by exhausting all possibilities on every step I take. It gives a more integrated feel to the analyser. Makes it more like a independent module which provides standard service rather than a dedicated module that works only for a specific strategy. 

Interchangeably, I can define each analysis step in a separate method and call it only upon need. The advantage of this approach is that when some analysis is not needed, it need not perform, saving time and space. 

The two design is does not exactly conflict with each other. Both design can co-exist at the same time. But I think it is important to point out the idea that the analysers are independent modules with no reliance over a specific strategy, which makes future design easier. 
