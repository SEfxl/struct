<?php
/**
 * @Desc:
 * @Date: ${DATA}
 * @Time: 4:27 下午
 */


class Section{

    /**
     * @desc 返回未覆盖区域的数量
     * @param array $interval
     * @return int
     */
    function sectionCover(array $interval) {
        $index0 = array_column($interval,0);
        $index1 = array_column($interval,1);
        array_multisort($interval,SORT_ASC,$index0,SORT_DESC,$index1);

        $left = $interval[0][0];
        $right = $interval[0][1];
        $num = 0;
        $length = count($interval);

        for ($i=1;$i<$length;$i++) {

            $compareLeft = $interval[$i][0];
            $compareRight = $interval[$i][1];
            //全覆盖
            if($left <= $compareLeft && $right >= $compareRight) {
                $num++;
            }
            //相交
            if($right > $compareLeft &&  $right < $compareRight) {
                $right = $compareRight;
            }
            //不相交
            if($right < $compareLeft) {
                $left = $compareLeft;
                $right = $compareRight;
            }
        }
        return $length - $num;
    }

    /**
     * 合并交叉区间,返回处理之后的区间
     * @param array $interval
     * @return array
     */
    function sectionMerge(array $interval) {

        $index0 = array_column($interval,0);
        $index1 = array_column($interval,1);
        array_multisort($interval,SORT_ASC,$index0,SORT_DESC,$index1);

        $length = count($interval);
        $result[] = $interval[0]; //以第一个为标准进行比较
        for ($i = 1; $i < $length; $i++) {
            $cur = $interval[$i];

            $len = count($result);
            $lastData = $result[$len-1];

            if($cur[0] <= $lastData[1]) {
                $result[$len-1][1] = $cur[1] > $lastData[1] ? $cur[1] : $lastData[1];
            }else {
                $result[] = $cur;
            }

        }

        return $result;
    }



}

$data = [
    [1, 4],
    [2, 8],
    [3, 6]
];
$obj = new Section();
$num = $obj->sectionCover($data);
echo "刨除覆盖区间,剩余区间：".$num."个".PHP_EOL;

$data = [
  [1,3],
  [2,6],
  [8,10],
  [15,18],
];
$result = $obj->sectionMerge($data);
echo "合并交叉区间后剩余区间：".PHP_EOL;
foreach ($result as $item) {
    echo "[".$item[0].",".$item[1]."]".PHP_EOL;
}
