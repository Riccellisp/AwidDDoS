% Designed to perform to detect malicious traffic running in network, this
% metric takes into account the source IPs Reference: Real-time DDoS attack 
% detection using FPGA,2017. Section 3 
function E = entropy2(d)
	if ischar(d), d=abs(d); end;
%     keyboard;
    [Y,I,J] = unique(d); 	
	H = sparse(J,1,1);
	p = full(H(H>0))/length(d);
	E = -sum(p.*log2(p));
end 