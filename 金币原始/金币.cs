using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class 金币 : MonoBehaviour
{
    public GameObject GO;
    public GUIText guit;
    public static int jin = 1000;
    // Start is called before the first frame update
    void Start()
    {
        GO.GetComponent<Text>().text = "1000";
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            Click();
        }
     }
    public string Add(int x)
    {
        jin = jin + x;
        string b = jin.ToString();
        return b;
    }
    public string Reduce(int x)
    {
        jin = jin - x;
        string b = jin.ToString();
        return b;
    }
    public void Click()
    {
            string c;
            c = Add(5);
            GO.GetComponent<Text>().text = c;   
    }
    public bool Judge()
    {
        if (jin > 0)
        {
            return true;
        }
        else return false;
    }
   public int Getnum()
    {
        return jin;
    }


}
