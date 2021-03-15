using System.Collections;
using System.Collections.Generic;
using UnityEngine;
// Rahul
public class CustomControllerLayer : MonoBehaviour
{
    // Start is called before the first frame update
    public uint GTID { get; set; }
    public Vector3 CurrentVelocity;
    public Vector3 CurrentAngularVelocity;
    public Bounds Bounds;
    public Vector3 pos;
    public Transform AgentTransform => transform;
    private Vector3 LastRBPosition;
    public Vector3 CurrentAcceleration;
    public Rigidbody rb;
    public int c = 1;
    void Start()
    {
        rb = GetComponent<Rigidbody>();
        SetGroundTruthBox();
        pos = transform.position;

    }
    // TODO Update
    private void PEDMove()
    {
        // if (CurrentSpeed != 0f)
        // {
             rb.MovePosition(rb.position + transform.forward * (1 * Time.fixedDeltaTime));
        // }
        //else
        {
            //rb.velocity = Vector3.zero;
        }

        var previousVelocity = CurrentVelocity;
        CurrentVelocity = (rb.position - LastRBPosition) / Time.fixedDeltaTime;
        CurrentAcceleration = CurrentVelocity - previousVelocity;
        LastRBPosition = rb.position;
    }

    public void SetGroundTruthBox()
    {
        PEDMove();
        var capsule = GetComponent<CapsuleCollider>();
        Bounds = new Bounds(transform.position, Vector3.zero);
        Bounds.size = new Vector3(capsule.radius * 2, capsule.height, capsule.radius * 2);

        // GroundTruth Box Collider
        var gtBox = new GameObject("GroundTruthBox");
        var gtBoxCollider = gtBox.AddComponent<BoxCollider>();
        gtBoxCollider.isTrigger = true;
        gtBoxCollider.size = Bounds.size;
        gtBoxCollider.center =transform.position;
        gtBox.transform.parent = transform;
        gtBox.layer = LayerMask.NameToLayer("GroundTruth");

    }

    // Update is called once per frame
    void Update()
    {
        c++;
        //Debug.Log($"in update {distance}");
    }
}

