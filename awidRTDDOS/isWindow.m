function response = isWindow(firstPacketWindowTime,packetWindowTime,windowLength)
 tFinal = firstPacketWindowTime + windowLength;
    if(packetWindowTime <= tFinal)
        response = 0;
    else
        response = 1;
    end
end