def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0: return []
        intervals=sorted(intervals)
        processed_intervals = [intervals[0]]
        for new_interval in intervals[1:]:
            new_start = new_interval[0]
            new_end = new_interval[1]
            overlap_indicator = 0
            for index, processed_interval in enumerate(processed_intervals):
                processed_end =  processed_interval[1]
                if new_start <= processed_end:
                    overlap_indicator=1
                    if new_end > processed_end   :
                        processed_intervals[index][1] = new_end
            if overlap_indicator==0:
                processed_intervals.append(new_interval)
        return (processed_intervals)
    
